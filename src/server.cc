#include <iostream>
#include <grpcpp/grpcpp.h>
#include "proto/hello.grpc.pb.h"
#include "proto/hello.grpc.pb.h"

class ProcessingImp : public ProcessingServices::Service {

   ::grpc::Status computeSum(::grpc::ServerContext* context, const ::Point3* request, ::Numeric* response){
    std::cout<<"sssss"<<std::endl;
        response->set_value(request->x() + request->y() + request->z());
        return grpc::Status::OK;
    }
   
    };

int main(){
    ProcessingImp service;
    grpc::ServerBuilder builder;
    builder.RegisterService(&service);
    builder.AddListeningPort("0.0.0.0:9999", grpc::InsecureServerCredentials());
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout<<"Server started on 9999"<<std::endl;
    server->Wait();

    return 0 ;
}