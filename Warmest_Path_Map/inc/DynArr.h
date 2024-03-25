#ifndef DYNARR_H
#define DYNARR_H

#include <iostream>

template<class T>
class DynArr{

	private:

		unsigned int length; // Current number of elements
		unsigned int capac; // Current capacity
		T* data;


		void copy(T* destin, T* origin, int len){

			for(unsigned int iter = 0; iter < len; ++iter){

				*(destin+iter) = origin[iter];
			}
		}

	public:

		DynArr(const int lengthIn = 0) :
			length(0),
			capac(lengthIn),
			data(new T[capac]) {}


		~DynArr(){
			delete [] data;
		}


		DynArr(const DynArr<T>& C) :
			length(C.length), capac(C.capac), data(new T[capac])
		{
			copy(data, C.data, C.length);
		}


		DynArr<T>& operator=(const DynArr<T>& assign){

			if(this != &assign){
				length = assign.length;
				capac = assign.capac;
				data = new T[capac];

				copy(data, assign.data, length);
			}

			return *this;
		}


		T& begin(){

			return data[0];
		}

		const T& begin() const{

			return data[0];
		}

		T& end(){

			return data[length - 1];
		}

		const T& end() const{

			return data[length-1];
		}

		unsigned int size() const{
			return length;
		}

		unsigned int capacity() const{
			return capac;
		}

		T& operator[](const unsigned int i){

			return data[i];
		}

		const T& operator[](const unsigned int i) const{

			return data[i];
		}


		void push_back(const T& value){

			if(length >= capac){

				if( length == 0 ){

					capac = 1;
				}

				else{
					capac = capac * 2;
				}

				T* tmp = new T[capac];

				copy(tmp, data, length);

				delete [] data;

				data = tmp;

			}

			data[length] = value;
			length++;

		}


		void erase(unsigned int e){

			// Error checking on the bounds
			if(e >= length){

				return;
			}

			// Reduce the length of the DynArr if
			// length is now less than half of the
			// current capacity
			if(length - 1 == capac / 2){
				capac = capac / 2;
			}

			T* tmp = new T[capac];

			unsigned int tmp_iter = 0;
			for(unsigned int data_iter = 0; data_iter < capac; ++data_iter){

				if( data_iter != e ){

					tmp[tmp_iter] = *(data + data_iter);
					++tmp_iter;

				}

			}

			delete [] data;
			data = tmp;
			--length;

		}


		friend std::ostream& operator<<( std::ostream& out, const DynArr<T>& theArray ){

			for( unsigned iter = 0; iter < theArray.size(); iter++ ){

				out << theArray[iter] << " ";

			}

			return out;
		}
};

#endif
