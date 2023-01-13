

int main() {
    cout<<"this is a simple test of the generic tree I implemented "<<endl;
    auto *arbre=new Arbre<int>(50);
    arbre->add( 10);
    arbre->add( -23);
    arbre->add( 45);
    arbre->add( 90) ;
    arbre->add( 70);
    arbre->add( 60);
    //print out the tree
    cout<< arbre;
    // suppression
    arbre->remove(50);
    arbre->remove(90);
    arbre->remove(70);
    cout<<"\n---------------print out the tree after deleting 50,90 and 70 --------------\n";
    cout<<arbre<<endl;
    cout<<"\n---------------looking for 80 and -23 in the tree --------------\n";
    cout<<(arbre->Search(80)?"80 exist":"80 doesn't exist")<<endl;
    cout<<(arbre->Search(-23)?"-23 exist":"-23 doesn't exist")<<endl;
  
  
  return 0;
}
