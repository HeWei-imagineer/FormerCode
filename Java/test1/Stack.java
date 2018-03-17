package test1;


//����ĳ���Ϊһ������ջ����ʵ��������ջ����
public class Stack {
	
	private SingleLinkedList list = new SingleLinkedList();
	
	public boolean empty() {
		return list.getSize()==0;
	}
	
	public int size() {
		return list.getSize();
	}
	
	//��ʵ��pop��������ջ����������(��������)��Ҫ��������Ƚ������FILO�ṹ
	public int pop() {
	  int size=size();
	  int num=0;
	  if(0==size){
		  return 0;
	  }
	  else if(1==size){
	   num=list.head.data;
	   list.head=list.tail=null;
	   list.size--;
	  
	  }
	  else{
		  Node temp=list.head;
		  for(int i=2;i<size;i++){
			  temp=temp.next;  
		  }
		  num=temp.next.data;
		  list.tail=temp;
		  if(temp.next.next==null){
			  list.tail.next=null;
		  }
		  list.size--;
		 } 
	 
	  return num;
	}
	
	//���ݽ�ջ����
	public void push(int data) {  
		list.add(data);
		
	}
	
	//ջ���ݸ���
	public Stack clone() {
		Stack s = new Stack();
		for(int i=0;i<list.getSize();i++) {
			s.list.add(list.get(i));
		}
		return s;
	}
	
	public static void main(String[] args) {
		Stack s1 = new Stack();
		s1.push(1);
		s1.push(2);
		s1.push(3);
		
		Stack s2 = s1.clone();
		
		System.out.println(s1.pop());
		System.out.println(s1.pop());
		System.out.println(s1.pop());
		
		System.out.println(s1.size());
		
	}
}

