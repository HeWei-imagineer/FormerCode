package homework2;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

import javax.lang.model.element.Element;

public class PrimeNumber {
	
	public static boolean isPnum(int i){
		if(i==0||i==1){
			return false;
		}
		int k=(int)Math.sqrt(i);
    	for(int j=2;j<=k;j++){
    		if((i%j)==0){
    			return false;
	       }
    	}
    	return true;
	}
	public static boolean eachNum(int k){
		//单个拼接 
        while(k!=0){
  	    int n1=k%10;
  	     if(isPnum(n1)){
  	    	 k=k/10;
  	     }
  	     else{
  	    	 return false;
  	     }
        }
        return true;
       
   }
	
    public static boolean twoNum(int k){
    	//2拼接
      int j=0;
      int n1=k%10;
      while((k/10)!=0){
    	 j++;
   	     if(k%10==0){
   	    	 k=k/10;
   	    	 n1=n1+(k%10)*(int)Math.pow(10, j);
   	    	 continue;
   	     } 
   	     k=k/10; 
   	     if(isPnum(n1)&&isPnum(k)){
   	    	return true;
   	     }
   	      n1=n1+(k%10)*(int)Math.pow(10, j);
         }
      
      return false;
	}
    
    public static boolean threeNum(int k){
    	 //3拼接
        //%10 /10 /100 /1000
        int[] arr=new int[4];
        int j=0;
        while((k/10)!=0){
      	  arr[j++]=k%10;
      	  k=k/10;
        }
        arr[j]=k;
        
        if(isPnum(arr[0])&&isPnum(arr[1])&&isPnum(arr[2]+arr[3]*10)){
      	   return true;
        }
        if(arr[2]!=0){
      	  if(isPnum(arr[0])&&isPnum(arr[3])&&isPnum(arr[1]+arr[2]*10)){
      		return true;
      	  }
        }
        if(arr[1]!=0){
      	  if(isPnum(arr[3])&&isPnum(arr[2])&&isPnum(arr[0]+arr[1]*10)){
      		return true;
      	  }
        }
        return false;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		threeNum(1234);
		int m=0;
		int [] Pnum=new int[1230];
        try {
        	FileOutputStream fos = new FileOutputStream("primeNum.txt");
        	OutputStreamWriter dos = new OutputStreamWriter(fos,"GBK");
        	PrintWriter fw = new PrintWriter(dos);
        	for(int i=1;i<10000;i++){	
            	if(isPnum(i)){
            		Pnum[m++]=i;
            		fw.println(i);
            	}
            	
            }
        	fw.close();
        	dos.close();
        	fos.close();
			
		} catch (Exception e) {
			// TODO: handle exception
		}
       System.out.println(m);
       
       try{
	   	FileOutputStream fos = new FileOutputStream("contactPnum.txt");
		OutputStreamWriter dos = new OutputStreamWriter(fos,"GBK");
		PrintWriter fw = new PrintWriter(dos);
		
		int count=0;
		for(int i=0;i<1230;i++){
	    	   int n=Pnum[i];
	    	   int k=0;
	    	   while((n/10)!=0){
	    		   k++;
	    		   n=n/10;
	    	   }
	    	   switch (k) {
			case 0:
				
				break;
	        case 1:
	        	if(eachNum(Pnum[i])){
					fw.println(Pnum[i]);
					count++;
				}
				
				break;
	        case 2:
	        	if(eachNum(Pnum[i])){
					fw.println(Pnum[i]);
					count++;
				}
	        	else{
	        		if(twoNum(Pnum[i])){
						fw.println(Pnum[i]);
						count++;
					}
	        	}
              break;
	        case 3:
	        	if(eachNum(Pnum[i])){
					fw.println(Pnum[i]);
					count++;
				}
	        	else if(twoNum(Pnum[i])){
				   fw.println(Pnum[i]);
				   count++;
	        	}
	        	else{
	        		if(threeNum(Pnum[i])){
	        		  fw.println(Pnum[i]);
	        		  count++;
	        		}
	        	}
              break;

			default:
				break;
			}
		}
		fw.println(count);
		fw.close();
    	dos.close();
    	fos.close();
		
		} catch (Exception e) {
			// TODO: handle exception
		}

      
      
       
          
          
          
       
       
	}
    

}
