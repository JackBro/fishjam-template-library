/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <uhttp/UHttpDef.h>
#include <uhttp/util/Logger.h>
#include <time.h>

static uHTTP::Logger *gUHttpLoggerSharedInstance = NULL;

//const int uHTTP::Logger::MAX_LINE_STRING = 512;
const char *uHTTP::Logger::SEPARATOR = " ";

uHTTP::Logger *uHTTP::Logger::GetSharedInstance() {
  if (!gUHttpLoggerSharedInstance)
    gUHttpLoggerSharedInstance = new Logger();
  return gUHttpLoggerSharedInstance;
}

void uHTTP::Logger::SetSharedInstance(uHTTP::Logger *logger) {
  if (gUHttpLoggerSharedInstance)
    delete gUHttpLoggerSharedInstance;
  gUHttpLoggerSharedInstance = logger;
}

const char *uHTTP::Logger::GetMaskString(int outputType) {
  switch (outputType) {
  case LoggerTarget::TRACE:
    return "TRACE";
  case LoggerTarget::DBG:
    return "DEBUG";
  case LoggerTarget::INFO:
    return "INFO";
  case LoggerTarget::WARN:
    return "WARN";
  case LoggerTarget::ERR:
    return "ERROR";
  case LoggerTarget::FATAL:
    return "FATAL";
  }
  
  return "UNKNOWN";
}

uHTTP::Logger::Logger() {
  setLevel(LoggerTarget::INFO);
}

uHTTP::Logger::~Logger() {
}

bool uHTTP::Logger::addTarget(LoggerTarget *target) {
  return this->targetList.addTarget(target);
}

bool uHTTP::Logger::clearAllTargets() {
  this->targetList.clear();
  return true;
}

int uHTTP::Logger::output(int outputType, const char *outputMessage) {
  if (outputType < getLevel())
    return 0;

  char logLineMessage[MAX_LINE_STRING] = { 0 };
  char localTimestampString[MAX_LINE_STRING] = { 0 } ;
  
  this->outputMutex.lock();
  
  time_t timestamp = time(NULL);
  struct tm *localTimestamp = localtime(&timestamp);
  strftime(localTimestampString, MAX_LINE_STRING - 1, "%c", localTimestamp);
  
  snprintf(logLineMessage, MAX_LINE_STRING - 1,
      "%s%s[%s] %s",
      localTimestampString,
      SEPARATOR,
      GetMaskString(outputType), 
      outputMessage);

  int outputedTargetCount = 0;
  
  for (LoggerTargetList::iterator outputTarget = this->targetList.begin(); outputTarget != this->targetList.end(); outputTarget++) {
    if (!(outputType & (*outputTarget)->getMask()))
      continue;
    if ((*outputTarget)->outputMessage(logLineMessage))
      outputedTargetCount++;
  }
  
  outputMutex.unlock();
  
  return outputedTargetCount;
}
