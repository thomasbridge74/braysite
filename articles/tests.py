from django.test import TestCase
from shared.models import Columnist
from .models import Article


class ArticleTestCase(TestCase):
    def setUp(self):
        self.columnist = Columnist.objects.create(
            name="Headmaster's Thoughts",
            author="Principal Skinner",
            description="Updates from Springfield Elementary",
        )
        self.article = Article.objects.create(
            title="Entry Posting 1",
            published_date='2010-01-01',
            body="Bart Simpson was here",
            columnist=self.columnist,
        )

    def test_article_details(self):
        self.assertEqual(str(self.article.columnist), "Principal Skinner")
        self.assertIn("Bart Simpson", self.article.body)
        self.assertEqual(str(self.article), "Entry Posting 1")