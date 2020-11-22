from django.db import models
import django.utils.timezone


class NewsReport(models.Model):
    publish_date = models.DateField(default=django.utils.timezone.now().date())
    headline = models.CharField(max_length=255)
    details = models.TextField()
    category = models.CharField(max_length=15)
    expire = models.DateField(null=True)

    def __str__(self):
        return self.headline
