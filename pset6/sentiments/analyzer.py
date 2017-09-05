import nltk

class Analyzer():
    """Implements sentiment analysis."""
    tokenizer = nltk.tokenize.TweetTokenizer()

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positives = set()
        self.negatives = set()

        # open positive list and load them into set
        file = open(positives, "r")
        for line in file:
            if not line.startswith(';') and not line.startswith(' '):
                self.positives.add(line.strip())
        file.close()

        # open negative list and load them into set
        file = open(negatives, "r")
        for line in file:
            if not line.startswith(';') and not line.startswith(' '):
                self.negatives.add(line.strip())
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokens = self.tokenizer.tokenize(text)
        score = 0
        for token in tokens:
            if token.lower() in self.positives:
                score += 1
            elif token.lower() in self.negatives:
                score -= 1
        return score