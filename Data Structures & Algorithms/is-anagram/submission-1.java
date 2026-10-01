class Solution {
    public boolean isAnagram(String s, String t) {

      HashMap<Character, Integer> map = new HashMap<>();

      for(var ch: s.toCharArray())
      {
         map.put(ch, map.getOrDefault(ch, 0) + 1);
      }  

      for(var ch: t.toCharArray())
      {
        map.put(ch, map.getOrDefault(ch, 0) - 1);
      }  


      for(var mp: map.entrySet())
      {
        if(mp.getValue() != 0) return false;
      }  

      return true;

    }
}
