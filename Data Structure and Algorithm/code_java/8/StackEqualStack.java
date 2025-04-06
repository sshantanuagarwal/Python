
import java.io.*;
	import java.util.*;
	import java.text.*;
	import java.math.*;
	import java.util.regex.*;

	class StackEqualStack{
	    int top;
	    int no_of_elements;
	    int pointer_for_push;
	    
	    ArrayList arl;
	    
	    StackEqualStack(int n){
	        top = n;
	        arl = new ArrayList(n);
	        no_of_elements = 0;
	        pointer_for_push = n-1;
	    }
	    
	    public void push(int n){
	        arl.add(pointer_for_push--,n);
	        no_of_elements++;
	    }
	    public Object pop(){
	        no_of_elements--;
	        return(arl.get(--top)); 
	    }
	    public void display(){
	        for (int i=0; i<no_of_elements; i++){
	            System.out.print(arl.get(i) + " ");
	        }
	        System.out.print("\n--------------\n ");
	    }
	}

	class Solution2 {
	    public void fun(){
	        
	        Scanner sc = new Scanner(System.in); // just accepting the array from user
	        int n1 = sc.nextInt();
	        int n2 = sc.nextInt();
	        int n3 = sc.nextInt();
	        
	        StackEqualStack stk1 = new StackEqualStack(n1);
	        StackEqualStack stk2 = new StackEqualStack(n2);
	        StackEqualStack stk3 = new StackEqualStack(n3);
	        
	        int sum1=0;
	        int sum2=0;
	        int sum3=0;
	        
	        int h1[] = new int[n1];
	        for(int i=0; i < n1; i++){
	            h1[i] = sc.nextInt();
	            stk1.push(h1[i]);
	            sum1 = sum1 + h1[i];
	        }
	        
	        int h2[] = new int[n2];
	        for(int i=0; i < n2; i++){
	            h2[i] = sc.nextInt();
	            stk2.push(h2[i]);
	            sum2 = sum2 + h2[i];
	        }
	        
	        int h3[] = new int[n3];
	        for(int i=0; i < n3; i++){
	            h3[i] = sc.nextInt();
	            stk3.push(h3[i]);
	            sum3 = sum3 + h3[i];
	        }
	        
	        stk1.display();
	        stk2.display();
	        stk3.display();
	        
	        while(true){
	            if(sum1>sum2 && sum1>sum3){
	                Object x = stk1.pop();
	                sum1 = sum1 - (int)x;
	            }
	            else if(sum2>sum1 && sum2>sum3){
	                Object x = stk2.pop();
	                sum2 = sum2 - (int)x;
	            }
	            else if(sum3>sum1 && sum3>sum2){
	                Object x = stk3.pop();
	                sum3 = sum3 - (int)x;
	            }
	            else if(sum1 == sum2 && sum2 == sum3){
	                System.out.println("here->"+sum2);
	                break;
	           }
	            
	        }
	        
	        
	    }
	    public static void main(String[] args) {
	        Solution2 ob = new Solution2();
	        ob.fun();
	    }
	}



