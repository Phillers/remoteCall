program callBack{
	version v1{
		void sendResult(int result) = 1;
		void returnData(int stream, string data<1024>) = 2;
	} = 1;
} =0x20000001;
		
		