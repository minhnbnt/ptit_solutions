import java.util.ArrayList;
import java.util.Scanner;
import view.InvoiceView;
import vn.edu.ptit.Invoice;
import vn.edu.ptit.Rule;
import vn.edu.ptit.Student;
import vn.edu.ptit.Subject;

class PaymentController {

	private final Student student;
	private final ArrayList<Subject> subjects;
	private final Rule rule;

	public PaymentController() {
		try (Scanner stdin = new Scanner(System.in)) {

			InputHelper helper = new InputHelper(stdin);

			this.student = helper.inputStudent();

			int numberOfSubjects = stdin.nextInt();
			this.subjects = new ArrayList<>(numberOfSubjects);

			for (int i = 0; i < numberOfSubjects; i++) {
				stdin.skip("\\s+");
				this.subjects.add(helper.inputSubjects());
			}

			stdin.skip("\\s+");
			this.rule = helper.inputRules();
		}
	}

	public double getAmount() {
		return this.subjects.stream()
		    .mapToDouble(s -> s.getCredit() * this.rule.getCreditPrice())
		    .reduce(0, Double::sum);
	}

	public Invoice getInvoice() {

		Invoice invoice = new Invoice(this.rule);

		invoice.setSt(this.student);
		invoice.setAlSubject(this.subjects);

		invoice.setAmount(this.getAmount());

		return invoice;
	}
}

class InputHelper {

	private final Scanner sc;

	public InputHelper(Scanner sc) {
		this.sc = sc;
	}

	public Student inputStudent() {

		Student s = new Student();

		s.setCode(sc.nextLine());
		s.setName(sc.nextLine());

		return s;
	}

	public Subject inputSubjects() {

		Subject s = new Subject();

		s.setCode(sc.nextLine());
		s.setName(sc.nextLine());
		s.setCredit(sc.nextInt());

		return s;
	}

	public Rule inputRules() {

		Rule r = new Rule();

		r.setCode(sc.nextLine());
		r.setName(sc.nextLine());
		r.setCreditPrice(sc.nextDouble());

		return r;
	}
}

public class HELLOJAR {
	public static void main(String[] args) {
		PaymentController pc = new PaymentController();
		// Output for test
		Invoice invoice = pc.getInvoice();
		InvoiceView.show(invoice);
	}
}
