//
// Created by cml on 25-4-12.
//
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Product{
  public:
    virtual void operation()=0;
    virtual ~Product(){}
};

class Product1: public Product{
  public:
    void operation(){
      cout<<"product 1"<<endl;
     }
};

class Product2: public Product{
  public:
    void operation(){
      cout<<"product 2"<<endl;
    }
};

// 简单工厂
class SampleFactory{
  public:
    unique_ptr<Product> createProduct(string productName){
    if(productName == "product 1"){
      return make_unique<Product1>();
    }else if(productName == "product 2"){
      return make_unique<Product2>();
    }
    return nullptr;
    };
};

// 工厂方法模式
class Factory{
  public:
    virtual unique_ptr<Product> createProduct()=0;
    virtual ~Factory(){}
};

class ConcreteFactory1:public Factory{
  public:
    unique_ptr<Product> createProduct(){
      return make_unique<Product1>();
    }
};

class ConcreteFactory2:public Factory{
  public:
    unique_ptr<Product> createProduct(){
      return make_unique<Product2>();
    }
};

int main(){
  // 简单工厂
  SampleFactory factory;
  factory.createProduct("product 1")->operation();
  factory.createProduct("product 2")->operation();

  // 工厂方法模式
  unique_ptr<Factory> factory1 = make_unique<ConcreteFactory1>();
  auto product1 = factory1->createProduct();
  product1->operation();

  unique_ptr<Factory> factory2 = make_unique<ConcreteFactory2>();
  auto product2 = factory2->createProduct();
  product2->operation();

  return 0;
}

