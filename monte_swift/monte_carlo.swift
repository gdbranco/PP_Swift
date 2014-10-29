type file;

app (file ret) reduce(file inps[], int _n_iter)
{
	reduce_c _n_iter @filenames(inps) stdout=@filename(ret);
}

app (file out) random_gen(int _iter, int seed)
{
	random_gen_c _iter seed stdout = @filename(out);
}

int tot = @toInt(@arg("tot", "1000"));
int procs = @toInt(@arg("procs", "4"));

tracef("tot_per_proc=%i procs=%i\n",tot,procs);
file outs[];
foreach i in [0:procs-1]{
	file outfile <single_file_mapper; file=@strcat("sim_",i,".out")>;
	outfile = random_gen(tot%/procs, i);
	outs[i] = outfile;
}
file result <"result.txt">; 
result = reduce(outs, tot);
