package homework2;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.*;



public class serverSocket {
	public void start(IOStrategy ios) {
		ServerSocket ss=new ServerSocket(2222);
		System.out.println("server is created");
		
				
	}
	public static void main(String[] args) throws Exception{
		try {
			
			ServerSocket ss = new ServerSocket(2222); 
		    while(true){
		    	Socket s= ss.accept();
		    	a.server(s);
		    	new Thread().start();
		    }
		    
		    InputStream in = s.getInputStream();
			OutputStream out = s.getOutputStream();
			DataInputStream dis = new DataInputStream(in);
			DataOutputStream dos=new DataOutputStream(out);
		    
			while(true){
				int command=dis.readInt();
			    switch (command) {
				case 1:
					dos.writeInt(dis.readInt()+dis.readInt());
					dos.flush();
					break;
	
				default:
					break;
				}
			}
		    
			
		} catch (Exception e) {
			// TODO: handle exception
		}
		
		
		
		
	}

}


