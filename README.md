<h3><b>A Resistor Network Simulator</b></h3>


1. Parser						- Done
2. Resistor Network Program		- Work in Progress
3. Resistor Network Simulator	- To be done



<u><h4>Parser</h4></u>
Validates input read from cin. Input is accepted one line at a time, with each
line terminated by a newline character. If an error is encountered when parsing a line, the program prints an error message and the line is discarded; processing resumes at the next line. The program continues to accept and parse until an End-Of-File (EOF) condition is received. The table below shows the valid commands, arguments and their output.

<table style="border-width: 0px; margin 0px; width:100%; height: 100%; padding:0px; border-collapse: collapse;">
    <tbody style="border-width: 0px; margin 0px; width:100%; height: 100%; padding:0px;">
	<tr>
		<th>Command</th>
		<th>Arguments</th>
		<th>Output if Command is Valid</th>
	</tr>
	<tr>
		<td>insertR</td>
		<td>name resistance nodeid nodeid</td>
		<td>Inserted: resistor <i>name</i> <i>resistance</i> Ohms <i>nodeid -> nodeid<i>
	</tr>
	<tr>
		<td>modifyR</td>
		<td>name resistance</td>
		<td>Modified: resitor <i>name</i> to <i>resistance</i> Ohms</td>
	</tr>
	<tr>
		<td>printR</td>
		<td>name</td>
		<td>Print: resistor <i>name</i></td>
	</tr>
	<tr>
		<td>printR</td>
		<td>all</td>
		<td>Print: all resistors</td>
	</tr>
	<tr>
		<td>printNode</td>
		<td>nodeid</td>
		<td>Print: node <i>nodeid</td>
	</tr>
	<tr>
		<td>printNode</td>
		<td>all</td>
		<td>Print: all nodes</td>
	</tr>
	<tr>
		<td>deleteR</td>
		<td>name</td>
		<td>Deleted: resistor <i>name</i></td>
	</tr>
	<tr>
		<td>deleteR</td>
		<td>all</td>
		<td>Deleted: all resistors</td>
	</tr>
   </tbody>
</table>
