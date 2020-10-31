#include "test.h"
#include "DnaSequence.h"

DnaSequence dna1("TGG");
DnaSequence dna2(dna1);
DnaSequence dna3("TTTTGGGGGGATGTAGGGGGGGGGGGAAGGTT");
DnaSequence dna5("TTTTT");
DnaSequence dna6("GGG");
std::string d="GGG";
DnaSequence dna7(d);
DnaSequence dna8("TTTTGGGGGGATGTAGGGGGGGGGGGAAGGTT");


void testOperatorEqual(){
    std::cout<<"testOperator=:"<<std::endl;
    std::cout<<dna6<<std::endl;
    dna5=dna6;
    std::cout<<dna5<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl<<std::endl;
}


void testGetDnaBits(){
    std::cout<<"testGetDnaBits:"<<std::endl;
    std::cout<<dna1.getDnaBits()<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl<<std::endl;
}


void testGetPackedSequence(){
    std::cout<<"testGetPackedSequence:"<<std::endl;
    std::cout<<dna1.getPackedSequence()<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl<<std::endl;
}


void testGetLenDnaBits(){
    std::cout<<"testGetLenDnaBits:"<<std::endl;
    std::cout<<dna1.getLenDnaBits()<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl<<std::endl;
}


void testOperatorCout(){
    std::cout<<"testOperator<<:"<<std::endl;
    std::cout<<"dna1: "<<std::endl<<dna1<<std::endl;
    std::cout<<"dna2: "<<std::endl<<dna2<<std::endl;
    std::cout<<"dna3: "<<std::endl<<dna3<<std::endl;
    std::cout<<"--------------------------------------------------------"<<std::endl<<std::endl;
}


void testOperatorIndex(){
    std::cout<<"testOperator[]:"<<std::endl;
    std::cout<<dna1<<std::endl;
    std::cout<<dna1[0]<<std::endl;
    std::cout<<dna1[1]<<std::endl;
    std::cout<<dna1[2]<<std::endl;
    std::cout<<"--------------------------------------------------------"<<std::endl<<std::endl;
}


void testSetNucleotide(){
    std::cout<<"testSetNucleotide:"<<std::endl;
    dna3.setNucleotide('A',8);
    std::cout<<dna3<<std::endl;
    std::cout<<"---------------------------------------------------"<<std::endl<<std::endl;
}


void testSlicing(){
    std::cout<<"testSlicing:"<<std::endl;
    std::cout<<dna3<<std::endl;
    std::cout<<dna3.slicing(1,26)<<std::endl;
    std::cout<<"----------------------------------------------------"<<std::endl<<std::endl;
}


void testFind(){
    std::cout<<"testFind:"<<std::endl;
    std::cout<<dna3<<std::endl;
    std::cout<<dna3.find("GGGGG")<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl<<std::endl;
}


void testFindAll(){
    std::cout<<"testFindAll:"<<std::endl;
    std::cout<<dna6<<std::endl;
    std::cout<<"testFindAll \"G\" in dna6 "<<std::endl;

    std::vector<size_t> dna1FindAll= dna6.findAll("G");

    for (std::vector<size_t >::iterator it = dna1FindAll.begin(); it != dna1FindAll.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl<<std::endl;
}


void testCount(){
    std::cout<<"testCount:"<<std::endl;
    std::cout<<dna3.count("G")<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl<<std::endl;
}


void testOperatorEqualEqual(){
    std::cout<<"testOperatorEqualEqual:"<<std::endl;
    if(dna1==dna2)
        std::cout<<"YES!!! DNA of dna1 and DNA of dna2 the same"<<std::endl;
    else
        std::cout<<"NO!!! DNA of dna1 and DNA of dna2 is not the same"<<std::endl;
    std::cout<<"----------------------------------------------"<<std::endl<<std::endl;
}


void testOperatorNotEqual(){
    std::cout<<"testOperatorNotEqual:"<<std::endl;
    if(dna1==dna3)
        std::cout<<"DNA of dna1 and DNA of dna3 the same"<<std::endl;
    else
        std::cout<<"NO!!! DNA of dna1 and DNA of dna3 is not the same"<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl<<std::endl;
}


void testLengthDna(){
    std::cout<<"testLengthDna:"<<std::endl;
    std::cout<<"len of dna2: "<<lengthDna(dna2)<<std::endl;
    std::cout<<"---------------------------------------------------"<<std::endl<<std::endl;
}


void testPairing(){
    std::cout<<"testPairing:"<<std::endl;
    std::cout<<dna1.pairing().getPackedSequence()<<std::endl;
    std::cout<<"---------------------------------------------------"<<std::endl<<std::endl;

}


void testFindConsensusSequences(){
    std::cout<<"testFindConsensusSequences:"<<std::endl;
    std::vector<DnaSequence> DnaFindConsensusSequences = dna8.findConsensusSequences();

    for ( std::vector<DnaSequence>::iterator it = DnaFindConsensusSequences.begin(); it != DnaFindConsensusSequences.end(); ++it)
{
        std::cout << *it<<" ";
    }
    std::cout << std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl<<std::endl;
}




void testWritingToFile(){
    std::cout<<"testWritingToFile:"<<std::endl;
    dna3.writeToFile("DNA1.txt");
    std::cout<<"-------------------------------------------------"<<std::endl<<std::endl;
}


/*
 *
 *
 *
 void testReadingFromFile(){
    std::cout<<"testReadingFromFile:"<<std::endl;
    DnaSequence dna9("DNA.txt","FILE");
    std::cout<<dna9<<std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl<<std::endl;
}*/