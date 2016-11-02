

###服务端

- 调用socket()创建套接字，调用bind()绑定ip和端口
- 调用accept(),监听连接请求
- 调用send()、recv()发送，接收数据
- 调用close()关闭socket


##客户端

- 调用socket()创建套接字
- 调用connect()连接服务器
- 调用send()、recv()发送，接收数据
- 调用close()关闭socket


#TCP:

##服务器：
- 创建socket();
- bind();
- listen();
- accept();
- 读数据recv().写数据send()
- 关闭socket(closesocket())

##客户端：
- 创建socket();
- connect();
- 写数据send(),读数据recv().
- 关闭socket(closesocket())

#UDP:
##服务器：

- 创建socket
- bind()
- recvfrom
- sendto
- closesocket()

##客户端：

- 创建socket
- bind()
- sendto
- recvfrom
- closesocket();
