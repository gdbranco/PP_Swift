type file;

app (file ret) reduce(file inps[], int _n_iter)
{
	_reduce _n_iter @filenames(inps) stdout=@filename(ret);
}

app (file out) call(int _iter, int i)
{
	random_gen _iter i stdout = @filename(out);
}

int tot_per_proc = @toInt(@arg("tot_per_proc", "1000"));
int procs = @toInt(@arg("procs", "3"));

tracef("tot_per_proc=%i procs=%i\n",tot_per_proc,procs);
file outs[];
foreach i in [0:procs-1]{
	file outfile <single_file_mapper; file=@strcat("sim_",i,".out")>;
	outfile = call(tot_per_proc, i);
	outs[i] = outfile;
}
file result <"result.txt">; 
result = reduce(outs, procs*tot_per_proc);
