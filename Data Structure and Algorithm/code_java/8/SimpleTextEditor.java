import java.util.Scanner;
import java.util.Stack;

public class SimpleTextEditor {

	public static void main(String srgs[]) {

		Scanner sc = new Scanner(System.in);
		int limit = sc.nextInt();
		Stack stack = new Stack();
		String s = "";

		for (int x = 0; x < limit; x++) {
			int ope = sc.nextInt();
			switch (ope) {
			case 1: // append
				stack.push(s);
				String append = sc.next();
				s += append;
				break;
			case 2: // erase last x characters
				stack.push(s);
				int character = sc.nextInt();
				s = s.substring(0, s.length() - character);
				break;
			case 3: // print
				int index = sc.nextInt();
				System.out.println(s.charAt(index - 1));
				break;
			case 4: // undo
				s = (String) stack.pop();
				break;
			default:
				break;
			}
		}
	}
}
