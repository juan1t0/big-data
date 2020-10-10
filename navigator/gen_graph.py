#!/usr/bin/env python
from sys import stdin
import re
import os
import json


def read_input(file):
	data = json.load(file)
	for i,paper in enumerate(data):
		if not paper.has_key('abstract'):
			continue
		yield (paper['id'], paper['references'])

def main(separator='\t'):
	data = read_input(stdin)

	for paper_id, refs in data:
		r = ""		
		for ref in refs:
			r += ref + ';'
		print '%s%s%s' % (paper_id, separator, r)

if __name__ == "__main__":
	main()
