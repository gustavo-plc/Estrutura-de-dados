int main()
{
  
inicio = criar_no (1);
// se inicio == NULL 
if(!inicio) 
    return 1;

inicio->prox = criar_no (2);
// se inicio->prox == NULL
if(!inicio->prox) 
    return 1;

inicio->prox->prox = criar_no (3);
// se inicio->prox->prox == NULL 
if(!inicio->prox->prox)
    return 1; 

inicio->prox->prox->prox = criar_no (4); // se inicio->prox->prox->prox == NULL 
if(!inicio->prox->prox->prox) 
    return 1;

    
    
    
    
    return 0;
}