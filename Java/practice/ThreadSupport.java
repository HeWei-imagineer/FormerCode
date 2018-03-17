package homework2;

import java.net.Socket;

public class ThreadSupport implements IOStrategy{
	private IOStrategy ios;
	
	public void service(Socket s) {
		new Thread().start();
		
	}
	public class IOThread extends Thread{
		private IOSstrategy ios;
		private Socket socket;
		
			
		
	}

}
