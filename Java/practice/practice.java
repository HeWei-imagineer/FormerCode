package homework2;

import java.awt.List;
import java.awt.Paint;
import java.awt.PaintContext;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;
import java.awt.image.ColorModel;
import java.beans.Beans;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Properties;

import javax.management.modelmbean.ModelMBean;
import javax.xml.bind.Marshaller.Listener;

public class practice {
//��������
	public class abc{
		private abc s1;
		private abc(){
			s1=null;
		}
		
		public abc getAbc(){
				if(s1!=null){
					return s1;
				}
		}
	}
}

//�򵥹���ģʽ
//Classloader;
//Class;
public abstract class product{
	public abstract void play();
}
public abstract class Aproduct extends product{
	public void play(){
		
	}
	public public Aproduct() {
		// TODO Auto-generated constructor stub
		return 
	}
}
public class productFactory{
	public product getProdut() {
		return Aproduct();
		
	}
	public product getProdut() {
		Class c= getClass();
		ClassLoader c1= getClasaLoader();
		String clazz="";
		Properties p= new Properties();
		p.load(new FileInputStream("a.properties"));
		
		return (product)Beans.instantiate(clazz,c1);
		
	}
}
//�۲���ģʽ
//javaʱ�䴦��ģʽ
//event delegation Model
//���Կ�ͷСд java bean�淶
class Student{
	private int age;
	List<AgeChangedListener> listeners=new ArrayList<AgeChangedListener>();
	public void addAgeChangedListener(AgeChangedListener acl) {
		if(!listeners.contains(acl)){
			Listener.add(acl);
		}
	}
	public int getAge() {
		return age;
	}
	
	public void process(AgeChangedEvent ace) {
		//for(int i=0;i<listener.size();i++){}
		for(Iterator<AgeChangedListener> iterator=listeners.iterator;iterator.hasNext();){
			AgeChangedListener acl=iterator.next();
			new Thread(){
				public void run() {
					// TODO Auto-generated method stub
                   acl.processAgeChanged(ace);
				}
			}.start();
		}
	}
	public void setAge(int age) {
		
		AgeChangedEvent ace = new AgeChangedEvent(this, this.age, age);
		process(ace);
		this.age=age;
		
	}
}

public class parent implements AgeChangedListener{
	@Override
	public void processAgeChanged(AgeChangedEvent a) {
		// TODO Auto-generated method stub
		
	}
}
public interface AgeChangedListener extends java.util.EventListener{
	public abstract void processAgeChanged(AgeChangedEvent a);
}
public class AgeChangedEvent extends java.util.EventObject{
	//private Object source;
	private int oldAge,newAge;
	public AgeChangedEvent(Student source,int oldAge,int newAge){
		super(source);
		
	}
}
public class MouseEvent extends java.util.EventObject() {
	public
}

//gui���
//awt
//swing
//javaFX
//swt

Paint p=new Paint() {
	
	@Override
	public int getTransparency() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	@Override
	public PaintContext createContext(ColorModel cm, Rectangle deviceBounds, Rectangle2D userBounds,
			AffineTransform xform, RenderingHints hints) {
		// TODO Auto-generated method stub
		return null;
	}
};

//LinkedBlockingQueue
//resultful ��״̬����,���ڷֲ�ʽ����
//MVCģ����ͼ������
//javax.swing ����չ
//GridLayout  Flay   ����  ��Ƭ����  ���񲼾� ������
//JFrame
//��������
//JTable

//javaWeb ������ʧ(���Ǳ���)

//session cookie url��д  form������   ������״̬
//session���л�(�ۻ�-�)invallidate()
//HttpSession

//filter
//requestDispatcher
//data sharing

private DataInputStream dis = null;
private DataOutputStream dos = null;

try{ 
   Properties propServer= new Properties();
   InputStream in = new BufferedInputStream(new FileInputStream("server.properties"));
   propServer.load(in);
   String hostIP=propServer.getProperty("hostIP");
   String hostPor=propServer.getProperty("hostPort"); 
   Socket s = new Socket(hostIP, Integer.parseInt(hostPor)); // ���Socket���󴴽���Ϻ��ʱ���٣�
   dis = new DataInputStream(s.getInputStream());
   dos = new DataOutputStream(s.getOutputStream());
	

} catch (Exception e) { 
	
}











