#ifndef OJBECTMAN_H
#define OJBECTMAN_H

#include <memory>

struct mine {
	int x, y;
}

template <typename Type>
class ObjectMan {
	public:
		ObjectMan(){}
		void addObject(Type object) {
			if (size == max) { increase(); }
            objects[size] = object;
            size++;
        }

        bool objectExists(Type object) {
            for (int i=0; i<size; i++) {
                if (objects[i] == object) {
                    return true;
                }
            }
            return false;
        }

        bool removeObject(Type object) {
            std::unique_ptr<Type[]> temp = std::make_unique<Type[]>(max);
            
            int j=0;
            for (int i=0; i<size; i++) {    
                if (objects[i] != object) {
                    temp[j] = objects[i];
                    j++
                }
            }

            objects.reset();
            objects = std::make_unique<Type[]>(max);
            for (int i=0; i<j; i++) {
                objects[i] = temp[i];
            }
            temp.reset();
            size = j;
        }

	private:
		int size;
		int max;
		std::unique_ptr<Type[]> objects;

//functions
        void increase() {
            std::unique_ptr<Type[]> temp = std::make_unique<Type[]>(max);
            for (int i=0; i<max; i++) {
                temp[i] = objects[i];
            }
            objects.reset();
            objects = std::make_unique<Type[]>(2*max);

            for (int i=0; i<max; i++) {
                objects[i] = temp[i];
            }
            temp.reset();
            max *= 2;
        }
};


