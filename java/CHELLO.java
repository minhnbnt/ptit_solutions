public class CHELLO {
	public static void main(String[] args) {
		Thread helloThread = new Thread(Hello::sayHello);
		helloThread.start();
	}
}

class Hello {
	public static void sayHello() {
		System.out.println("Hello PTIT.");
	}
}
