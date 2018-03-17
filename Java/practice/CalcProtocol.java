package homework2;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class CalcProtocol implements IOStrategy {
	
	    public void service(Socket s) {
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
		}
		
}
