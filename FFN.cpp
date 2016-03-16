//
//  FFN.cpp
//  Neural Networks
//
//  Created by Alexis Louis on 15/03/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#include "FFN.hpp"

FFN::FFN(){
}

void FFN::add_layer(Layer *l){
    layers.push_back(l);
}

void FFN::initFFN(int nb_inputs_neurons, int nb_hidden_neurons, int nb_outputs_neurons){
    this->add_layer(new Layer(0, nb_inputs_neurons, this));
    this->add_layer(new Layer(1, nb_hidden_neurons, this));
    this->add_layer(new Layer(2, nb_outputs_neurons, this));
}

void FFN::sim(vector<float> inputs){
    layers[0]->set_inputs(inputs);
    for(int indice = 0; indice < this->get_nb_layers(); indice++){
        this->get_layer_at(indice)->forward_propagate();
    }
    
}

void FFN::train(vector<float> inputs, vector<float> targets){
    layers[0]->set_inputs(inputs);
    this->set_targets(targets);
    for(int indice = 0; indice < this->get_nb_layers(); indice++){
        this->get_layer_at(indice)->forward_propagate();
        
    }
    for(int indice = this->get_nb_layers()-1; indice >=0; indice--){
        this->get_layer_at(indice)->calc_deltas();
        this->get_layer_at(indice)->calc_new_weights();
        
    }
}

void FFN::about(){
    cout << "Number of layers : "<< layers.size() << endl;
    cout << "Number of input neurons : "<< layers[0]->get_nb_neurons() << endl;
    cout << "Number of hidden neurons : "<< layers[1]->get_nb_neurons() << endl;
    cout << "Number of output neurons : "<< layers[2]->get_nb_neurons() << endl;
}

vector<float> FFN::get_ffn_outputs(){
    return this->get_layer_at(this->get_nb_layers()-1)->get_outputs();
}

void FFN::set_targets(vector<float> tar){
    targets = tar;
}