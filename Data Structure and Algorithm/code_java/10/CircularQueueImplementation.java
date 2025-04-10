	import java.util.Arrays;

public class CircularQueueImplementation {

	public static void main(String[] args) {

		CircularQueue<Integer> circularQueue = new CircularQueue<Integer>(8);

		circularQueue.enqueue(15);
		circularQueue.enqueue(16);
		circularQueue.enqueue(17);
		circularQueue.enqueue(18);
		circularQueue.enqueue(19);
		circularQueue.enqueue(20);
		circularQueue.enqueue(21);
		circularQueue.enqueue(22);

		System.out.println("Full Circular Queue" + circularQueue);

		System.out.print("Dequeued following element from circular Queue ");
		System.out.println(circularQueue.dequeue() + " ");
		circularQueue.enqueue(23);
		System.out.println("After enqueueing circular queue with element having value 23");
		System.out.println(circularQueue);
		System.out.println(circularQueue.dequeue());
	}

}

// implementation of Circular Queue using Generics
class CircularQueue<E> {

	private int currentSize; // Current Circular Queue Size
	private int[] circularQueueElements;
	private int maxSize; // Circular Queue maximum size

	private int rear;// rear position of Circular queue(new element enqueued at
						// rear).
	private int front; // front position of Circular queue(element will be
						// dequeued from front).

	public CircularQueue(int maxSize) {
		this.maxSize = maxSize;
		circularQueueElements = new int[this.maxSize];
		currentSize = 0;
		front = 0;
		rear = 0;
	}

	/**
	 * Enqueue elements to rear.
	 */
	public void enqueue(int item) {
		if (isFull()) {
			System.out.println("Circular Queue is full. Element cannot be added");
		} else {
			circularQueueElements[rear] = item;
			rear = (rear + 1) % circularQueueElements.length;
			currentSize++;
		}
	}

	/**
	 * Dequeue element from Front.
	 */
	public int dequeue() {
		int deQueuedElement = 0;
		if (isEmpty()) {
			System.out.println("Circular Queue is empty. Element cannot be retrieved");
		} else {
			deQueuedElement = circularQueueElements[front];
			circularQueueElements[front] =-1;
			front = (front + 1) % circularQueueElements.length;
			currentSize--;
		}
		return deQueuedElement;
	}

	/**
	 * Check if queue is full.
	 */
	public boolean isFull() {
		return (currentSize == circularQueueElements.length);
	}

	/**
	 * Check if Queue is empty.
	 */
	public boolean isEmpty() {
		return (currentSize == 0);
	}

	@Override
	public String toString() {
		return "CircularQueue [" + Arrays.toString(circularQueueElements) + "]";
	}

}
