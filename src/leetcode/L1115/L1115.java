// Link: https://leetcode.com/problems/print-foobar-alternately/
package src.leetcode.L1115;

import java.util.concurrent.Semaphore;

class FooBar {
  private int n;
  private Semaphore fooSem;
  private Semaphore barSem;

  public FooBar(int n) {
    this.n = n;
    this.fooSem = new Semaphore(1);
    this.barSem = new Semaphore(0);
  }

  public void foo(Runnable printFoo) throws InterruptedException {

    for (int i = 0; i < n; i++) {
      fooSem.acquire();
      // printFoo.run() outputs "foo". Do not change or remove this line.
      printFoo.run();
      barSem.release();
    }
  }

  public void bar(Runnable printBar) throws InterruptedException {

    for (int i = 0; i < n; i++) {
      barSem.acquire();
      // printBar.run() outputs "bar". Do not change or remove this line.
      printBar.run();
      fooSem.release();
    }
  }
}

class PrintFoo implements Runnable {
  @Override
  public void run() {
    System.out.print("foo");
  }
}

class PrintBar implements Runnable {
  @Override
  public void run() {
    System.out.print("bar");
  }
}

class Driver {
  public static void main(String[] args) {
    PrintFoo printFoo = new PrintFoo();
    PrintBar printBar = new PrintBar();
    FooBar fooBar = new FooBar(2);

    Thread T1 = new Thread(new Runnable() {
      @Override
      public void run() {
        try {
          fooBar.foo(printFoo);
        } catch (InterruptedException ie) {
        }
      }
    });

    Thread T2 = new Thread(new Runnable() {
      @Override
      public void run() {
        try {
          fooBar.bar(printBar);
        } catch (InterruptedException ie) {
        }
      }
    });

    T1.start();
    T2.start();
  }
}