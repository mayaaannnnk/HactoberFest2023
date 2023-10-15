class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedList {
    Node head;

    public void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head; // Make it point to itself for a single-node circular list.
        } else {
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }
            current.next = newNode;
            newNode.next = head;
        }
    }

    public void prepend(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head;
        } else {
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }
            current.next = newNode;
            newNode.next = head;
            head = newNode;
        }
    }

    public void delete(int data) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        Node prev = null;

        do {
            if (current.data == data) {
                if (current == head) {
                    // If the node to delete is the head, adjust the head.
                    Node last = head;
                    while (last.next != head) {
                        last = last.next;
                    }
                    head = head.next;
                    last.next = head;
                } else {
                    prev.next = current.next;
                }
                System.out.println(data + " deleted from the list.");
                return;
            }
            prev = current;
            current = current.next;
        } while (current != head);

        System.out.println(data + " not found in the list.");
    }

    public void display() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        do {
            System.out.print(current.data + " -> ");
            current = current.next;
        } while (current != head);
        System.out.println(" (head)");
    }

    public static void main(String[] args) {
        CircularLinkedList circularList = new CircularLinkedList();

        while (true) {
            System.out.println("\nCircular Linked List Menu:");
            System.out.println("1. Append a node");
            System.out.println("2. Prepend a node");
            System.out.println("3. Delete a node by value");
            System.out.println("4. Display the list");
            System.out.println("5. Exit");

            java.util.Scanner scanner = new java.util.Scanner(System.in);
            int choice, data;
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter data to append: ");
                    data = scanner.nextInt();
                    circularList.append(data);
                    break;
                case 2:
                    System.out.print("Enter data to prepend: ");
                    data = scanner.nextInt();
                    circularList.prepend(data);
                    break;
                case 3:
                    System.out.print("Enter data to delete: ");
                    data = scanner.nextInt();
                    circularList.delete(data);
                    break;
                case 4:
                    circularList.display();
                    break;
                case 5:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
