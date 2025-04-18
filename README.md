# cluster-chat-
基于muduo库，工作在nginx tcp负载均衡环境中的集群聊天客户端、服务端项目

编译方式：
cd build
rm -rf *
cmake ..
make

需要nginx 的tcp负载均衡，并加载muduo库，启动redis，mysql
然后运行bin中的两个文件进行集群聊天

