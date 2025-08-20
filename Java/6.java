class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        String ret = "";
        int stride = (numRows-1)*2;
        int len = s.length();
        for (int row = 0; row < numRows; row++) {
            int firstStep = row == numRows - 1 ? stride : stride - row*2;
            int secondStep = row == 0 ? stride : row*2;
            boolean first = false;

            for (int index = row; index < len; index+= first ? firstStep : secondStep) {
                ret += s.charAt(index);
                first = !first;
            }
        }

        return ret;
    }
}
