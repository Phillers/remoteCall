program remoteCall{
	version v1{
		void callCommand(string command) = 1;
		void sendData(string data<1024>, int size) = 2;
	} = 1;
} =0x20000001;
		
		
