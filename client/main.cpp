#include"Client.h"
#include"ConsoleSender.h"
int main(){
	LogReader reader("./wtmpx","./logins.dat");
	ConsoleSender sender;
	Client client(reader,sender);
	client.dataMine();
	return 0;
}
