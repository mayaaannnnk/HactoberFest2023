class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class DoublyLinkedList {
    Node head;

    public void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            newNode.prev = current;
        }
    }

    public void prepend(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        if (head != null) {
            head.prev = newNode;
        }
        head = newNode;
    }

    public void insertAfter(int data, int targetData) {
        Node newNode = new Node(data);
        Node current = head;
        while (current != null) {
            if (current.data == targetData) {
                newNode.next = current.next;
                if (current.next != null) {
                    current.next.prev = newNode;
                }
                current.next = newNode;
                newNode.prev = current;
                break;
            }
            current = current.next;
        }
    }

    public void deleteNode(int data) {
        Node current = head;
        while (current != null) {
            if (current.data == data) {
                if (current.prev != null) {
                    current.prev.next = current.next;
                } else {
                    head = current.next;
                }
                if (current.next != null) {
                    current.next.prev = current.prev;
                }
                return;
            }
            current = current.next;
        }
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " <-> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        DoublyLinkedList linkedList = new DoublyLinkedList();
        while (true) {
            System.out.println("\nDoubly Linked List Menu:");
            System.out.println("1. Append a node");
            System.out.println("2. Prepend a node");
            System.out.println("3. Insert after a node");
            System.out.println("4. Delete a node by value");
            System.out.println("5. Display the list");
            System.out.println("6. Exit");

            java.util.Scanner scanner = new java.util.Scanner(System.in);
            int choice, data, targetData;
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter data to append: ");
                    data = scanner.nextInt();
                    linkedList.append(data);
                    break;
                case 2:
                    System.out.print("Enter data to prepend: ");
                    data = scanner.nextInt();
                    linkedList.prepend(data);
                    break;
                case 3:
                    System.out.print("Enter data to insert: ");
                    data = scanner.nextInt();
                    System.out.print("Enter target data: ");
                    targetData = scanner.nextInt();
                    linkedList.insertAfter(data, targetData);
                    break;
                case 4:
                    System.out.print("Enter data to delete: ");
                    data = scanner.nextInt();
                    linkedList.deleteNode(data);
                    break;
                case 5:
                    linkedList.display();
                    break;
                case 6:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
