from django.db import models
from shared.models import Columnist


class Article(models.Model):
    title = models.CharField(max_length=70)
    published_date = models.DateField(auto_now=False)
    body = models.TextField()
    columnist = models.ForeignKey(Columnist, on_delete=models.PROTECT)

    def __str__(self):
        return self.title

