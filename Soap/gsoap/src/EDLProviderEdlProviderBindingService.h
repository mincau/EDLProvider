/* EDLProviderEdlProviderBindingService.h
   Generated by gSOAP 2.8.18 from D:\Sandbox\EdlProvider\Soap\gsoap\src\EDLProviderInterface.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef EDLProviderEdlProviderBindingService_H
#define EDLProviderEdlProviderBindingService_H
#include "EDLProviderH.h"
class SOAP_CMAC EdlProviderBindingService : public soap
{ public:
	/// Variables globally declared in D:\Sandbox\EdlProvider\Soap\gsoap\src\EDLProviderInterface.h (non-static)
	/// Constructor
	EdlProviderBindingService();
	/// Construct from another engine state
	EdlProviderBindingService(const struct soap&);
	/// Constructor with engine input+output mode control
	EdlProviderBindingService(soap_mode iomode);
	/// Constructor with engine input and output mode control
	EdlProviderBindingService(soap_mode imode, soap_mode omode);
	/// Destructor, also frees all deserialized data
	virtual ~EdlProviderBindingService();
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to defaults
	virtual	void reset();
	/// Initializer used by constructor
	virtual	void EdlProviderBindingService_init(soap_mode imode, soap_mode omode);
	/// Create a copy
	virtual	EdlProviderBindingService *copy() SOAP_PURE_VIRTUAL;
	/// Close connection (normally automatic)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Return sender-related fault to sender
	virtual	int soap_senderfault(const char *string, const char *detailXML);
	/// Return sender-related fault with SOAP 1.2 subcode to sender
	virtual	int soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML);
	/// Return receiver-related fault to sender
	virtual	int soap_receiverfault(const char *string, const char *detailXML);
	/// Return receiver-related fault with SOAP 1.2 subcode to sender
	virtual	int soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML);
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif
	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Run simple single-thread iterative service on port until a connection error occurs (returns error code or SOAP_OK), use this->bind_flag = SO_REUSEADDR to rebind for a rerun
	virtual	int run(int port);
	/// Bind service to port (returns master socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET bind(const char *host, int port, int backlog);
	/// Accept next request (returns socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET accept();
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
	/// Then accept SSL handshake, when SSL is used
	virtual	int ssl_accept();
#endif
	/// Serve this request (returns error code or SOAP_OK)
	virtual	int serve();
	/// Used by serve() to dispatch a request (returns error code or SOAP_OK)
	virtual	int dispatch();

	///
	/// Service operations (you should define these):
	/// Note: compile with -DWITH_PURE_VIRTUAL for pure virtual methods
	///

	/// Web service operation 'getInstalledEdls' (returns error code or SOAP_OK)
	virtual	int getInstalledEdls(edlprovider__InstalledEdlsResponseType &edlprovider__installedEdlsResponse) SOAP_PURE_VIRTUAL;

	/// Web service operation 'getEdl' (returns error code or SOAP_OK)
	virtual	int getEdl(edlprovider__EdlCreateRequestType *edlprovider__getEdlRequest, edlprovider__EdlCreateResponseType &edlprovider__getEdlResponse) SOAP_PURE_VIRTUAL;

	/// Web service operation 'getEdlDouble' (returns error code or SOAP_OK)
	virtual	int getEdlDouble(edlprovider__EdlCreateRequestDoubleType *edlprovider__getEdlDoubleRequest, edlprovider__EdlCreateResponseType &edlprovider__getEdlResponse) SOAP_PURE_VIRTUAL;
};
#endif
