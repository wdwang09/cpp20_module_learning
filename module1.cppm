export module module1;

export import module2;

export import :sub1;

export import :sub2_interface;
import :sub2_impl;

export int f1() { return 1; }

export namespace f {

int f2() { return 2; }

int f3() { return 3; }

}  // namespace f

export {
  int f4() { return 4; }

  int f5();
}

module :private;

int f5() { return 5; }
