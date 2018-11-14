#include "poly.h"

Poly::Poly(){
	i_power = 0;
	data.push_back(0);
}

Poly::Poly(int zeroPower){
	i_power = 0;
	data.push_back(zeroPower);
}

Poly::Poly(const Poly & poly1){
	for(int i = 0;i <= poly1.getPower(); i++){
		data.push_back(poly1.getPosition(i));
	}
	i_power = poly1.getPower();
}

float & Poly:: operator[] (int position){
	if(position > i_power){
		for(int i = i_power; i <= position; i++){
			data.push_back(0);
		}
		i_power = position;
		return data[position];
	}
	else{
		return data[position];
	}
}

int Poly::getPower() const{
	return i_power;
}

float Poly::getPosition(int position) const{
	return data[position];
}

void Poly::swap(Poly & poly1){
	data.swap(poly1.data);
	int aux_power = poly1.i_power;
	poly1.i_power = i_power;
	i_power = aux_power;
}

Poly& Poly::operator = (const Poly & poly1){
	if(this == &poly1){
		return *this;
	}
	Poly n(poly1);
	swap(n);
	i_power = poly1.getPower();
	return *this;
}	

Poly& Poly::operator += (const Poly & poly1){
	if(poly1.getPower() > i_power){
		for(int i = 0; i <= i_power; i++){
			data[i] += poly1.getPosition(i);
		}
		for(int i = i_power+1;i <= poly1.getPower(); i++){
			data.push_back(poly1.getPosition(i));
		}
		i_power = poly1.getPower();
	}
	else{
		for(int i = 0; i <= poly1.getPower();i++){
				data[i] += poly1.getPosition(i);
		}
	}
	return *this;		
}

Poly& Poly::operator *= (const Poly & poly1){
	int size = i_power + poly1.getPower()+1;
		vector<float> aux_data(size, 0);
		for(int i = 0;i < i_power;i++){
			for(int x = 0;x < poly1.getPower();x++){
				aux_data[i+x] = data[i]*poly1.getPosition(x);
			}
		}
		data.clear();
		data = aux_data;
		i_power = size-1;
		return *this;	
}

double Poly::operator() (double p) const{
		double val = 0;
		for(int i = 0; i <= i_power;i++){
		val += data[i]*pow(p,i);
	    }
	    return val;
}

ostream & operator << (ostream & s, const Poly & poly1){
	for(int i = poly1.getPower();i >= 0;i--){
		    if(poly1.getPosition(i) > 0 && i == 0){
				s << "+" << poly1.getPosition(i);
		    }
		    else if(poly1.getPosition(i) > 0 && i == 1){
				s << "+" << poly1.getPosition(i) << "*x" << " ";
		    }	    
		    else if(poly1.getPosition(i) > 0 && i != poly1.getPower()){
				s << "+" << poly1.getPosition(i) << "*x^" << i << " ";
		    }
		    else if(poly1.getPosition(i) >0 && i == poly1.getPower()){
				s << poly1.getPosition(i) << "*x^" << i << " ";
		    }
	}
	return s;
}
