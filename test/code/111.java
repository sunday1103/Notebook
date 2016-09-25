public class Test {
    public static void main(String args[]) {
        int x[] = new int[15];
        final int y[] = x;
        y[5] = 123;
        System.out.println(y[5]);
    };