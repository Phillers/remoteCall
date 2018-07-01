program remoteCall{
	version v1{
		int callCommand(string command) = 1;
		void sendData(string data<1024>) = 2;
	} = 1;
} =0x20000001;
		
		
