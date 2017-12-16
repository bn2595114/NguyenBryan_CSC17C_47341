/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryNode.h
 * Author: Bryan
 *
 * Created on December 15, 2017, 3:11 PM
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <cstdlib>

using namespace std;

template <class T>
class BinaryNode {
private:
	BinaryNode *left;
	BinaryNode *right;
	T data;
public:
	BinaryNode( T data ){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	virtual ~BinaryNode(){
		delete left;
		delete right;
	}

    void setData(T data) {
    	this->data = data;
    }

    T GetData() const {
    	return data;
    }

    void setRight(BinaryNode* right) {
    	this->right = right;
    }

    BinaryNode* getRight() const {
    	return right;
    }

    void setLeft(BinaryNode* left) {
    	this->left = left;
    }

    BinaryNode* getLeft() const {
    	return left;
    }
	

};

#endif /* BINARYNODE_H */

