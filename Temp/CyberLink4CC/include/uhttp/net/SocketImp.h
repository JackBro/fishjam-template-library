/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CNET_SOCKETIMP_H_
#define _CNET_SOCKETIMP_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#if defined(WIN32) && defined(ITRON) && defined (_AFXDLL)
#include <afxwin.h>
#endif

#if (defined(WIN32) || defined(__CYGWIN__)) && !defined(ITRON)
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(BTRON) || defined(TENGINE) 
#include <typedef.h>
#elif defined(ITRON)
#include <kernel.h>
#endif

#include <string>
#include <uhttp/UHttpDef.h>
#include <uhttp/util/TimeUtil.h>

#if (!defined(WIN32) && !defined(__CYGWIN__)) || defined(ITRON)
#if defined(BTRON) || defined(TENGINE) 
typedef W SOCKET;
#elif defined(ITRON)
typedef ER SOCKET;
#else
typedef int SOCKET;
#endif
#endif

namespace uHTTP {
class SocketImp {
 public:
  SocketImp();
  ~SocketImp();

  ////////////////////////////////////////////////
  // Static Members
  ////////////////////////////////////////////////

 public:
  static const int STREAM;
  static const int DGRAM;

  ////////////////////////////////////////////////
  //  Static Methods
  ////////////////////////////////////////////////

 public:
  static size_t GetInstanceCount();

  ////////////////////////////////////////////////
  //  Socket
  ////////////////////////////////////////////////
  
 public:
  void setSocket(SOCKET value) {
    m_sock = value;
  }

  SOCKET getSocket() {
    return m_sock;
  }

  ////////////////////////////////////////////////
  // bind
  ////////////////////////////////////////////////
  
 public:
  bool isBound();
  
  ////////////////////////////////////////////////
  // close
  ////////////////////////////////////////////////

public:
  
  bool close();
  
  ////////////////////////////////////////////////
  //  Local address/port
  ////////////////////////////////////////////////

 public:
  void setLocalAddress(const std::string &addr) {
    m_localAddr = addr;
    //StripIPv6ScopeID(addr, localAddr);
  }

  const char *getLocalAddress() {
    return m_localAddr.c_str();
  }

  void setLocalPort(int port) {
    m_localPort = port;
  }

  int getLocalPort() {
    return m_localPort;
  }

  ////////////////////////////////////////////////
  // Type
  ////////////////////////////////////////////////

protected:
  
  void setType(int value) {
    m_type = value;
  }

 public:
  int getType() {
    return m_type;
  }

  ////////////////////////////////////////////////
  // Error Code
  ////////////////////////////////////////////////

protected:
  
  void setErrorCode(int code) {
    this->m_errorCode = code;
  }

 public:
  int getErrorCode() const {
    return this->m_errorCode;
  }

  ////////////////////////////////////////////////
  //  Socket Option
  ////////////////////////////////////////////////

 public:
  bool setReuseAddress(bool on);
  void setTimeout(int timeout);

  #if defined(TENGINE) && defined(TENGINE_NET_KASAGO)
  bool setMulticastInterface(const std::string &ifaddr);
  #endif

private:

  int m_type;
  std::string m_localAddr;
  int m_localPort;
  int m_errorCode;

protected:
  SOCKET  m_sock;
  CTimeUtil m_TimeUtil;

};

void SocketStartup();
void SocketCleanup();

}

#endif
