type file;

app (file ret) reduce(file inps[], int _n_iter)
{
	calc_pi _n_iter @filenames(inps) stdout=@filename(ret);

}

app (file out) call(int _iter, int i)
{
	monte_carlo_c _iter i stdout = @filename(out);
}

int iter = @toInt(@arg("iter", "1000"));
int n_iter = @toInt(@arg("n_iter", "3"));

tracef("iter=%i n_iter=%i\n",iter,n_iter);
file outs[];
foreach i in [0:n_iter-1]{
	file outfile <single_file_mapper; file=@strcat("sim_",i,".out")>;
	outfile = call(iter, i);
	outs[i] = outfile;
}
file result <"result.txt">; 
result = reduce(outs, n_iter*iter);
