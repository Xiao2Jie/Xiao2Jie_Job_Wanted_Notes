1. 客户端发送FIN给服务端，自己进入FIN_WAIT_1状态
2. 服务端收到FIN后，发送ACK确认，自己进入CLOSE_WAIT状态，客户端收到ACK后进入FIN_WAIT_2状态
3. 服务端发送FIN,自己进入LAST_ACK状态
4. 客户端收到了FIN,发送ACK确认，自己进入TIME_WAIT状态；服务端收到ACK后进入关闭状态；若客户端2MSL后还没有收到服务端消息，就表示服务端已经关闭了，自己进入关闭状态。

---
![](http://i.imgur.com/afqewwH.png)

1 此时TCP连接两端都还处于ESTABLISHED状态，客户端停止发送数据，并发出一个FIN报文段。首部FIN=1，序号seq=u（u等于客户端传输数据最后一字节的序号加1）。客户端进入FIN-WAIT-1(终止等待1)状态。

2 服务端回复确认报文段，确认号ack=u+1，序号seq=v（v等于服务端传输数据最后一字节的序号加1），服务端进入CLOSE-WAIT(关闭等待)状态。现在TCP连接处于半开半闭状态，服务端如果继续发送数据，客户端依然接收。

3 客户端收到确认报文，进入FIN-WAIT-2状态，服务端发送完数据后，发出FIN报文段，FIN=1，确认号ack=u+1，然后进入LAST-ACK(最后确认)状态。

4 客户端回复确认确认报文段，ACK=1，确认号ack=w+1（w为半开半闭状态时，收到的最后一个字节数据的编号） ，序号seq=u+1，然后进入TIME-WAIT(时间等待)状态。 

注意此时连接还没有释放，需要时间等待状态结束后(4分钟) 连接两端才会CLOSED。设置时间等待是因为，有可能最后一个确认报文丢失而需要重传。

[来源nowcoder](http://www.nowcoder.com/test/question/done?tid=4898163&qid=1019)