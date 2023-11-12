class Solution
{
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    public static boolean isRotated(String str1, String str2)
    {
        // Your code here
        if (str1.length() != str2.length()) {
            return false;
        }

        return str2.equals(str1.substring(2) + str1.substring(0, 2)) || str2.equals(str1.substring(str1.length() - 2) + str1.substring(0, str1.length() - 2));
    }
    
}
