/*
 * Allocator.cpp
 *
 *  Created on: 25-Apr-2012
 *      Author: Alok
 */

/*
 * One of the main reasons for writing a custom allocator is performance.
 * The default allocator uses operator new to allocate memory.
 * Default Allocator may work well with containers who mostly allocate large chunks of memory, like vector and deque.
 * However, for containers that require frequent allocations of small objects, such as map and list, using the default allocator is generally slow.
 * Other common problems with a malloc-based allocator include poor locality of reference,[4] and excessive memory fragmentation.
 *
 * A popular approach to improve performance is to create a memory pool-based allocator.
 * Instead of allocating memory every time an item is inserted or removed from a container, a large block of memory (the memory pool) is allocated beforehand, possibly at the startup of the program.
 * The custom allocator will serve individual allocation requests by simply returning a pointer to memory from the pool.
*/

// The following is a fully conforming allocator implementation using malloc and free as its allocation primitives.
// Largely based on Austern's example and the default allocator example, with only minor adjustments of style
// (such as the idiomatic use of the keyword typename in the type-parameter of the template-declarations).

#include <cstddef> // size_t, ptrdiff_t
#include <cstdlib> // malloc, free
#include <new> // bad_alloc

template<typename T> struct allocator;
// the allocator must be able to be instantiated for void
template<> struct allocator<void> {
  typedef void value_type;
  typedef void* pointer;
  typedef const void* const_pointer;
  template <typename U> struct rebind { typedef allocator<U> other; };
};

template <typename T> struct allocator {
  typedef T* pointer;
  typedef T& reference;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T value_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  template <typename U> struct rebind { typedef allocator<U> other; };

  allocator() {}
  // an allocator can be constructed from an allocator instantiated on a different type
  template <typename U> allocator(const allocator<U>&) {}

  pointer address(reference x) const { return &x; }
  const_pointer address(const_reference x) const { return &x; }

  pointer allocate(size_type n, allocator<void>::pointer = 0) {
    void* p = std::malloc(n * sizeof(T));
    if (!p) // allocate may throw in case of failure
      throw std::bad_alloc();
    return pointer(p);
  }
  void deallocate(pointer p, size_type) throw() { std::free(p); }
  // any larger number will cause the result of the computation (n * sizeof(T)) to wrap around
  size_type max_size() const { return size_type(-1) / sizeof(T); }

  void construct(pointer p, const value_type& x) { new(p) T(x); }
  void destroy(pointer p) { p->~T(); }
};

// all allocators should be equivalent
template <typename T, typename U>
bool operator==(const allocator<T>&, const allocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const allocator<T>&, const allocator<U>&) { return false; }
