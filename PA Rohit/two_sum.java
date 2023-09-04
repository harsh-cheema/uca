import java.util.*;

public class two_sum{
    
    public static int[] find_index(int[] nums, int target) {
        int arr[]=new int[2];
        HashMap<Integer,Integer> s=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
            if(s.containsValue(target-nums[i])){
                for(Map.Entry<Integer,Integer> mp:s.entrySet()){
                    if(mp.getValue()==target-nums[i]){
                         arr[0]=mp.getKey();
                         arr[1]=i;
                         return arr;
                    }
                }
            }
            s.put(i,nums[i]);
        }
        return arr;
    }
    public static void main(String[] args) {
        int arr[]={3,1,2,3};
        int arr2[]=find_index(arr, 6);
        for(int i=0;i<arr2.length;i++){
            System.out.println(arr2[i]);
        }
        
    }
}