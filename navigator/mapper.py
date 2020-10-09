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
		yield (paper['id'], (paper['abstract'] + ' ' +paper['title']).split())

def main(separator='\t'):
	data = read_input(stdin)

	for paper_id, words in data:
		for word in words:
			print '%s%s%s' % (word, separator, paper_id)

if __name__ == "__main__":
	main()
