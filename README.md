Build the image 
docker build -t grpc_1 .
Run the container on port 9999
docker compose up 
you should get the following output :
server started on 9999
To test :
create new grpc req under Postman 
import the .proto file 
Invoke the  service

