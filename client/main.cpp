#include"Client.h"
#include"ConsoleSender.h"
#include"SocketSender.h"
int main(){
	LogReader reader("./wtmpx","./logins.dat");
	//ConsoleSender sender;
	SocketSender sender("./failFile.dat",8080,"127.0.0.1");
	Client client(reader,sender);
	client.dataMine();
	return 0;
}
