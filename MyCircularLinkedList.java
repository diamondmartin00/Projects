import java.util.NoSuchElementException;
public class MyCircularLinkedList<E> implements MyList<E> {
    private Node<E> tail = null;
    private int size = 0;
    public MyCircularLinkedList() {
    }
    public E getFirst() {
        if (tail == null)
            throw new NoSuchElementException();
        return tail.next.element;
    }
    public E getLast() {
        if (tail == null)
            throw new NoSuchElementException();
        return tail.element;
    }
    public void addFirst(E e) {
        Node<E> newNode = new Node<E>(e);
        if (tail == null) {
            tail = newNode;
            tail.next = tail;
        }
        else {
            newNode.next = tail.next;
            tail.next = newNode;
        }
        size++;
    }
    public void addLast(E e) {
        Node<E> newNode = new Node<E>(e);
        if (tail == null) {
            tail = newNode;
            tail.next = tail;
        }
        else {
            newNode.next = tail.next;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }
    @Override
    public void add(int index, E e) {
        if (index >= 0 && index <= size) {
            if (index == 0) {
                addFirst(e);
            }
            else if (index == size) {
                addLast(e);
            }
            else {
                Node<E> current = tail.next;
                Node<E> previous = tail;
                for (int i = 0;i < index; i++) {
                    previous = current;
                    current = current.next;
                }
                Node<E> newNode = new Node<E>(e);
                previous.next = newNode;
                newNode.next = current;
                size++;
            }
        }
        else {
            throw new IndexOutOfBoundsException("Illegal index of " + index + " passed to CircularList remove method.");
        }
    }
    public E removeFirst() {
        if (tail != null) {
            E temp = tail.next.element;
            if (tail.next == tail) {
                tail = null;
            }
            else
                tail.next = tail.next.next;
            size--;
            return temp;
        }
        throw new NoSuchElementException();
    }
    public E removeLast() {
        if (tail != null) {
            E temp = tail.element;
            if (tail.next == tail) {
                tail = null;
            }
            else {
                Node<E> current = tail.next;
                while (current.next != tail) {
                    current = current.next;
                }
                current.next = tail.next;
                tail = current;
            }
            size--;
            return temp;
        }
        throw new NoSuchElementException();
    }
    @Override
    public E remove(int index) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                return removeFirst();
            }
            else if (index == size - 1) {
                return removeLast();
            }
            else {
                Node<E> current = tail.next;
                Node<E> previous = tail;
                for (int i = 0; i < index; i++) {
                    previous = current;
                    current = current.next;
                }
                previous.next = current.next;
                size--;
                return current.element;
            }
        }
        else {
            throw new IndexOutOfBoundsException("Illegal index of " + index + " passed to CircularList remove method.");
        }
    }
    @Override
    public String toString() {
        String result = "[";
        if (size > 0) {
            Node<E> current = tail.next;
            while (current != tail) {
                result += current.element.toString() + ", ";
                current = current.next;
            }
            result += tail.element.toString();
        }
        result += "]";
        return result;
    }
    @Override
    public void clear() {
        size = 0;
        tail.next = tail = null;
    }
    @Override
    public boolean contains(Object e) {
        if (size == 0) {
            return false;
        }
        else {
            Node<E> current = tail.next;

            while (current != null) {
                if (current.element == e)
                    return true;
                current = current.next;
            }
        }
        return false;
    }
    @Override
    public E get(int index) {
        if (index >= 0 && index < size) {
            if (index == 0)
                return getFirst();
            else if (index == size - 1)
                return getLast();
            else {
                Node<E> current = tail.next;
                int i = 0;
                while (i < index) {
                    current = current.next;
                    i++;
                }
                return current.element;
            }
        }
        else {
            throw new IndexOutOfBoundsException("Illegal index of " + index + " passed to MyCircularLinkedList get method.");
        }
    }
    @Override
    public int indexOf(Object e) {
        if (size > 0) {
            int idx = 0;
            Node<E> current = tail.next;
            while (true) {
                if (current.element.equals(e))
                    return idx;
                else if (current == tail)
                    break;
                current = current.next;
                idx++;
            }
        }
        return -1;
    }
    @Override
    public int lastIndexOf(E e) {
        int index = -1;
        if (size > 0) {
            int i = 0;
            Node<E> current = tail.next;
            while (true) {
                if (current.element.equals(e)) {
                    index = i;
                }
                else if (current == tail) {
                    break;
                }
                current = current.next;
                i++;
            }
        }
        return index;
    }
    @Override
    public E set(int index, E e) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                E element = tail.next.element;
                tail.next.element = e;
                return element;
            }
            else if (index == size - 1) {
                E element = tail.element;
                tail.element = e;
                return element;
            }
            else {
                Node<E> current = tail.next;
                int i = 0;
                while (i < index) {
                    current = current.next;
                    i++;
                }
                E element = current.element;
                current.element = e;
                return element;
            }
        }
        else {
            throw new IndexOutOfBoundsException("Illegal index of " + index + " passed to CircularList set method.");
        }
    }
    @Override
    public java.util.Iterator<E> iterator() {
        return new MyCircularLinkedListIterator();
    }
    private class MyCircularLinkedListIterator implements java.util.Iterator<E> {
        private Node<E> current = tail.next;
        int num = 0;
        @Override
        public boolean hasNext() {
            return (num < size);
        }
        @Override
        public E next() {
            num++;
            E e = (E) current.element;
            current = current.next;
            return e;
        }
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
    private class Node<E> {
        E element;
        Node<E> next;
        public Node(E element) {
            this.element = element;
            next = null;
        }
    }
    @Override
    public int size() {
        return size;
    }
}