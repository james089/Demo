// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "imageProcService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class imageProcServiceHandler : virtual public imageProcServiceIf {
 public:
  imageProcServiceHandler() {
    // Your initialization goes here
  }

  void Revert(std::string& _return, const std::string& image, const int32_t width, const int32_t height) {
    // Your implementation goes here
    printf("Revert\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<imageProcServiceHandler> handler(new imageProcServiceHandler());
  shared_ptr<TProcessor> processor(new imageProcServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

