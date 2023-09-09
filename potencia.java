public class potencia {
    public int potencia(int base, int exp){
	if(exp == 1)
		return base;
	else if (exp == 0)
		return 1;
	else
		return base * potencia(base,exp-1);

}

    
}
